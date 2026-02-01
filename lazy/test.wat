(module
  (type $type0 (func (param i32 i32)(result i32)))
  (import "math" "add" (func $add (param i32 i32) (result i32)))
  (import "math" "mul" (func $mul (param i32 i32) (result i32)))
  (func (export "add_and_square") (param i32 i32) (result i32)
    ;; Function to add 2 numbers and square it ((a + b)^2).
    ;; Exported as "add_and_square".
    (call $mul
      (call $add (local.get 0) (local.get 1))
      (call $add (local.get 0) (local.get 1))
    )
  )
  (func (export "sum_of_squares") (param i32 i32) (result i32)
    ;; Function to calculate the sum of squares (a^2 + b^2).
    ;; Exported as "sum_of_squares".
    (call $add
      (call $mul (local.get 0) (local.get 0))
      (call $mul (local.get 1) (local.get 1))
    )
  )
)