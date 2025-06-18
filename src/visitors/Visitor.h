#pragma once

class Disk;
class Directory;
class TextFile;
class ImageFile;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(Disk& disk) = 0;
    virtual void visit(Directory& dir) = 0;
    virtual void visit(TextFile& file) = 0;
    virtual void visit(ImageFile& file) = 0;
};