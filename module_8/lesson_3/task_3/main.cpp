#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

enum class Type {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
public:
    LogMessage(Type type, const std::string& text) : type_(type), text_(text) {}
    
    Type type() const {
        return type_;
    }
    
    const std::string& message() const {
        return text_;
    }

private:
    Type type_;
    std::string text_;
};

class LogHandler {
public:
    LogHandler(LogHandler* handler = nullptr) : nextHandler(handler) {}
    virtual ~LogHandler() = default;

    void setNext(LogHandler* handler) {
        nextHandler = handler;
    }

    virtual void handleMessage(const LogMessage& message) = 0;

protected:
    LogHandler* nextHandler;
};

class FatalError : public LogHandler {
public:
    void handleMessage(const LogMessage& message) override {
        if (message.type() == Type::FatalError) {
            std::cout << "Fatal Error" << std::endl;
            throw std::runtime_error(message.message());
        } else if (nextHandler) {
            nextHandler->handleMessage(message);
        }
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

    void handleMessage(const LogMessage& message) override {
        if (message.type() == Type::Error) {
            out << "Error: " << message.message() << std::endl;
        } else if (nextHandler) {
            nextHandler->handleMessage(message);
        }
    }

private:
    std::ofstream out;
};

class Warning : public LogHandler {
public:
    void handleMessage(const LogMessage& message) override {
        if (message.type() == Type::Warning) {
            std::cout << "Warning: " << message.message() << std::endl;
        } else if (nextHandler) {
            nextHandler->handleMessage(message);
        }
    }
};

class Unknown : public LogHandler {
public:
    void handleMessage(const LogMessage& message) override {
        if (message.type() == Type::Unknown) {
            std::cout << "Unknown: " << message.message() << std::endl;
        } else if (nextHandler) {
            nextHandler->handleMessage(message);
        }
    }
};

int main() {
    LogMessage log1(Type::Error, "This is an error");
    LogMessage log2(Type::Warning, "This is a warning");
    LogMessage log3(Type::Unknown, "Unknown message");
    LogMessage log4(Type::FatalError, "This is a fatal error, program will be closed");

    FatalError fatalErrorHandler;
    Error errorHandler("error.log");
    Warning warningHandler;
    Unknown unknownHandler;

    fatalErrorHandler.setNext(&errorHandler);
    errorHandler.setNext(&warningHandler);
    warningHandler.setNext(&unknownHandler);

    try {
        fatalErrorHandler.handleMessage(log1);
        fatalErrorHandler.handleMessage(log2);
        fatalErrorHandler.handleMessage(log3);
        fatalErrorHandler.handleMessage(log4); 
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
