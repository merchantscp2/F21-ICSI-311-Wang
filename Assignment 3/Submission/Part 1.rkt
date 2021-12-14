; Part 1: Recursive Abs -- Merchant, A

; Things to consider:
; We can use the build in abs function
; Lists are not mutatble so we need to create a new list with the abs entries
; No sublists need to be considered

; Create a new function abs_list which takes a list as an argument
; and returns a list with the absolute values of the input list
(define (abs_list lst)
  ; If the list is null
  (if (null? lst)
      ; Return an empty list
      '()
      ; If it's not null, construct a list starting with the abs of the first element
      (cons (abs (car lst))
            ; Add the tail which also calls the function on the remaining list
            (abs_list (cdr lst)))))

; Test empty list
(abs_list '())
; Test single element list
(abs_list '(-1))
; Test 0 & -0
(abs_list '(0 -0))
; Test decimal
(abs_list '(-102.392 039.2381))
; General tests
(abs_list '( -41   180.32   -16   528  -272))
(abs_list '(-979  -558.3   282   840   871))
(abs_list '(-611  -288   701   562  -233))
(abs_list '(   5   921.129   753  -539  -673))
(abs_list '(-289  -840   537  -139   837))
(abs_list '( 361   545  -892.129  -605  -166))
(abs_list '(-577  -652  -743  -634  -787))
(abs_list '( 608  -776  -695  -230   145))
(abs_list '( 399  -887    29  -501.948   892))
(abs_list '( 982   197  -209    25    31))
(abs_list '(-453   745  -682.1294  -210   867))
(abs_list '( -59   289   423  -341   653))
(abs_list '(-404  -783   476  -851    17))
(abs_list '( 223   585   331  -836  -554))
(abs_list '( 287  -585   962  -622   508))
(abs_list '(-931  -480   895   531   391))