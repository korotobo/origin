#include <fstream>
#include <iostream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class MessageCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "Console: " << message << '\n';
    }
};

class FileCommand : public LogCommand {
public:
    FileCommand() {
        out.open("log.txt", std::ios::app);
        if (!out.is_open()) {
            std::cout << "No log file found" << '\n';
        }
    }

    ~FileCommand() {
        out.close();
    }

    void print(const std::string& message) override {
        if (out.is_open()) {
            out << message << '\n';
        }
    }

private:
    std::ofstream out;
};

void executeLog(LogCommand& command, const std::string& message) {
    command.print(message);
}

int main() {
    MessageCommand consoleLogger;
    FileCommand fileLogger;

    executeLog(consoleLogger, "Hello, World!");

    executeLog(fileLogger, "Hello, World!");

    return 0;
}
