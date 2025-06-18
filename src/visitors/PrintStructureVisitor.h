#pragma once
#include "Visitor.h"

class PrintStructureVisitor : public Visitor {
public:
    void visit(Disk& disk) override;
    void visit(Directory& dir) override;
    void visit(TextFile& file) override;
    void visit(ImageFile& file) override;
};