#pragma once
#include "Visitor.h"

class CalculateSizeVisitor : public Visitor {
public:
    void visit(Disk& disk) override;
    void visit(Directory& dir) override;
    void visit(TextFile& file) override;
    void visit(ImageFile& file) override;

    size_t getTotalSize() const;
private:
    static size_t totalSize;
};