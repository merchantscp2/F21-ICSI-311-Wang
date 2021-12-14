; Part 3: Bubble Sort a List -- Merchant, A

; Things to consider:
; No sublists
; Just consider numbers

; Puts the largest integer at the end
(define (tail_largest lst)
  ; Switch conditions
  (cond
    ; If the remainder of the list is null, at end, pass lst
    ((null? (cdr lst)) lst)
    ; If the second instance is grater then the first, we keep checking it against the rest
    ((> (cadr lst) (car lst)) (cons (car lst) (tail_largest (cdr lst))))
    ; If the second instasnce is smaller or equal, pass by it and check the next till it's the last
    (else (cons (cadr lst) (tail_largest (cons (car lst) (cddr lst)))))
    )
  )

; Iteration helper.
(define (bubble_sort_helper lst len)
  ; If it's length is one, we're done just do it once more and return it
  (if (= len 1) (tail_largest lst)
      ; If its longer, recursively check the next and decrease the counter
        (bubble_sort_helper (tail_largest lst) (- len 1))))

; Wrapper function for above, takes in standard list
(define (bubble_sort lst)
  ; Check that the list isn't null, and if it is, return empty list
  (if (null? lst) '()
  ; Passes the list and its initial length to the helper funcs if it's not null
  (bubble_sort_helper lst (length lst))))

; Test empty list
(bubble_sort '())
; Test single list
(bubble_sort '(0))
; Test negative numbers
(bubble_sort '(3 0 -2 -4 -9 193))
; Test multiple same numbers
(bubble_sort '(3 1 3 2 3))
; Test nothing needs to be swapped
(bubble_sort '(0 1 2 3 4 5 6 7 8 9))
; General cases
(bubble_sort '(109 38 1823 127491  381 329 19))
(bubble_sort '(0 0 0 1 3 28 39 1 2 39))
(bubble_sort '(-9 2 013 9 203 92 8))
(bubble_sort '(9 8 37 1 293 019))
(bubble_sort '(9 8 7 6 5 4 3 2 1 0))