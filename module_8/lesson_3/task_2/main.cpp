#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    virtual ~Observer() = default; 
};

class Observed {
public:
    void AddObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(Observer* observer) {
        auto it = std::remove(observers_.begin(), observers_.end(), observer);
        observers_.erase(it, observers_.end());
    }

    void onWarning(const std::string& message) {
        for (auto observer : observers_) {
            observer->onWarning(message);
        }
    }

    void onError(const std::string& message) {
        for (auto observer : observers_) {
            observer->onError(message);
        }
    }

    void onFatalError(const std::string& message) {
        for (auto observer : observers_) {
            observer->onFatalError(message);
        }
    }

private:
    std::vector<Observer*> observers_;
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }
};

class ErrorObserver : public Observer {
public:
    ErrorObserver() {
        out.open("errors.log");
        if (!out.is_open()) {
            std::cout << "No log file found" << std::endl;
        }
    }

    ~ErrorObserver() {
        out.close();
    }

    void onError(const std::string& message) override {
        out << "Error message: " << message << std::endl;
    }

private:
    std::ofstream out;
};

class FatalErrorObserver : public Observer {
public:
    FatalErrorObserver() {
        out.open("fatal_errors.log");
        if (!out.is_open()) {
            std::cout << "No log file found" << std::endl;
        }
    }

    ~FatalErrorObserver() {
        out.close();
    }

    void onFatalError(const std::string& message) override {
        out << "Fatal error message: " << message << std::endl;
        std::cout << "Fatal Error: " << message << std::endl;
    }

private:
    std::ofstream out;
};

int main() {
    Observed object;
    WarningObserver warning;
    ErrorObserver error;
    FatalErrorObserver fatal;

    object.AddObserver(&warning);
    object.AddObserver(&error);
    object.AddObserver(&fatal);

    object.onWarning("This is a warning message.");
    object.onError("This is an error message.");
    object.onFatalError("This is a fatal error message.");

    return 0;
}
