#pragma once
#include <string>
#include <vector>
#include <memory>

class Visitor; 

class FileSystemNode {
public:
    explicit FileSystemNode(const std::string& name) : name(name) {}
    virtual ~FileSystemNode() = default;

    virtual void accept(Visitor& visitor) = 0;
    std::string getName() const { return name; }

protected:
    std::string name;
};