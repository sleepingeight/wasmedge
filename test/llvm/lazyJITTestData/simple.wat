(module
  ;; Simple add function
  (func $add (export "add") (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.add
  )

  ;; Simple multiply function
  (func $mul (export "mul") (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.mul
  )

  ;; Simple subtract function
  (func $sub (export "sub") (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.sub
  )

  ;; Constant return function
  (func $const42 (export "const42") (result i32)
    i32.const 42
  )

  ;; Unused function 1
  (func $unused1 (export "unused1") (param i32) (result i32)
    local.get 0
    i32.const 100
    i32.add
  )

  ;; Unused function 2
  (func $unused2 (export "unused2") (param i32 i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.add
    local.get 2
    i32.mul
  )
)

