#include <fstream>
#include <string>
#include <stdexcept>

class HTMLPrintable {
public:
    virtual std::string printAsHTML() const = 0;
};

class TextPrintable {
public:
    virtual std::string printAsText() const = 0;
};

class JSONPrintable {
public:
    virtual std::string printAsJSON() const = 0;
};

class Data {
public:
    Data(std::string data) : data_(std::move(data)) {}
    virtual ~Data() = default;

protected:
    std::string data_;
};

class TextData : public Data, public TextPrintable {
public:
    TextData(std::string data) : Data(std::move(data)) {}

    std::string printAsText() const override {
        return data_;
    }
};

class HTMLData : public Data, public HTMLPrintable {
public:
    HTMLData(std::string data) : Data(std::move(data)) {}

    std::string printAsHTML() const override {
        return "<html>" + data_ + "</html>";
    }
};

class JSONData : public Data, public JSONPrintable {
public:
    JSONData(std::string data) : Data(std::move(data)) {}

    std::string printAsJSON() const override {
        return "{ \"data\": \"" + data_ + "\" }";
    }
};

void saveToText(std::ofstream &file, const TextPrintable& printable) {
    file << printable.printAsText();
}

void saveToHTML(std::ofstream &file, const HTMLPrintable& printable) {
    file << printable.printAsHTML();
}

void saveToJSON(std::ofstream &file, const JSONPrintable& printable) {
    file << printable.printAsJSON();
}

int main() {
    std::ofstream file("output.txt");

    TextData textData("Hello, World!");
    HTMLData htmlData("Hello, World!");
    JSONData jsonData("Hello, World!");

    saveToText(file, textData);
    saveToHTML(file, htmlData);
    saveToJSON(file, jsonData);

    file.close();
    return 0;
}
