#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

enum class MessageType {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
public:
    LogMessage(MessageType type, const std::string& text) : type_(type), text_(text) {}

    MessageType type() const {
        return type_;
    }

    const std::string& message() const {
        return text_;
    }

private:
    MessageType type_;
    std::string text_;
};

class LogHandler {
public:
    LogHandler(LogHandler* handler = nullptr) : next_(handler) {}
    virtual ~LogHandler() = default;

    void setNext(LogHandler* handler) {
        next_ = handler;
    }

    void receiveMessage(const LogMessage& msg) {
        if (canHandle() == msg.type()) {
            handleMessage(msg);
        } else if (next_) {
            next_->receiveMessage(msg);
        } else {
            throw std::runtime_error("Error: no handler for this message was found!");
        }
    }

protected:
    virtual void handleMessage(const LogMessage& msg) = 0;
    virtual MessageType canHandle() const = 0;

private:
    LogHandler* next_;
};

class FatalError : public LogHandler {
protected:
    void handleMessage(const LogMessage& msg) override {
        throw std::runtime_error(msg.message());
    }

    MessageType canHandle() const override {
        return MessageType::FatalError;
    }
};

class Error : public LogHandler {
public:
    Error(const std::string& filename) {
        out.open(filename);
        if (!out.is_open()) {
            std::cout << "No log file found" << std::endl;
        }
    }

    ~Error() {
        if (out.is_open()) {
            out.close();
        }
    }

protected:
    void handleMessage(const LogMessage& msg) override {
        out << "Error: " << msg.message() << std::endl;
    }

    MessageType canHandle() const override {
        return MessageType::Error;
    }

private:
    std::ofstream out;
};

class Warning : public LogHandler {
protected:
    void handleMessage(const LogMessage& msg) override {
        std::cout << "Warning: " << msg.message() << std::endl;
    }

    MessageType canHandle() const override {
        return MessageType::Warning;
    }
};

class Unknown : public LogHandler {
protected:
    void handleMessage(const LogMessage& msg) override {
        std::cout << "Unknown: " << msg.message() << std::endl;
    }

    MessageType canHandle() const override {
        return MessageType::Unknown;
    }
};

int main() {
    LogMessage log1(MessageType::Error, "This is an error");
    LogMessage log2(MessageType::Warning, "This is a warning");
    LogMessage log3(MessageType::Unknown, "Unknown message");
    LogMessage log4(MessageType::FatalError, "This is a fatal error, program will be closed");

    FatalError fatalErrorHandler;
    Error errorHandler("error.log");
    Warning warningHandler;
    Unknown unknownHandler;

    fatalErrorHandler.setNext(&errorHandler);
    errorHandler.setNext(&warningHandler);
    warningHandler.setNext(&unknownHandler);

    try {
        fatalErrorHandler.receiveMessage(log1);
        fatalErrorHandler.receiveMessage(log2);
        fatalErrorHandler.receiveMessage(log3);
        fatalErrorHandler.receiveMessage(log4);
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
