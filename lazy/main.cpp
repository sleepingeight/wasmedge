#include "common/configure.h"
#include "common/spdlog.h"
#include "vm/vm.h"
#include <iostream>

int main() {
  WasmEdge::Configure conf;
  conf.getRuntimeConfigure().setEnableJIT(true);
  conf.getRuntimeConfigure().setLazyJIT(true);
  conf.getCompilerConfigure().setOptimizationLevel(
      WasmEdge::CompilerConfigure::OptimizationLevel::O0);
  WasmEdge::Log::setDebugLoggingLevel();
  WasmEdge::VM::VM vm(conf);
  vm.registerModule("math", "lib.wasm");
  vm.loadWasm("test.wasm");
  vm.validate();
  vm.instantiate();
  auto res = vm.execute("add_and_square",
                        {WasmEdge::ValVariant(10), WasmEdge::ValVariant(20)},
                        {WasmEdge::ValType(WasmEdge::TypeCode::I32),
                         WasmEdge::ValType(WasmEdge::TypeCode::I32)});
  std::cout << res->at(0).first.get<uint32_t>() << std::endl;
  res = vm.execute("add_and_square",
                   {WasmEdge::ValVariant(2), WasmEdge::ValVariant(20)},
                   {WasmEdge::ValType(WasmEdge::TypeCode::I32),
                    WasmEdge::ValType(WasmEdge::TypeCode::I32)});
  std::cout << res->at(0).first.get<uint32_t>() << std::endl;
  vm.cleanup();
}