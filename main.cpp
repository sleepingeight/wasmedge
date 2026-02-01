#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include <iostream>
#include <memory>

using namespace llvm;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input.ll>\n";
        return 1;
    }
    LLVMContext Context;
    SMDiagnostic Err;

    std::unique_ptr<Module> M = parseIRFile(argv[1], Err, Context);
    if (!M) {
        Err.print(argv[0], errs());
        return 1;
    }
    for (const Function &F : *M) {
        if (!F.isDeclaration()) {
            std::cout << "Function: " << F.getName().str() << "\n";
        }
    }

    return 0;
}
