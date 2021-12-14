; Part 2a: Removing Atoms -- Merchant, A

; Things to consider:
; Nested lists must be considered
; Think of an atom as a character

; Function to remove any atom from a given list, even deeply nested
 (define (remove_atom atm lst)
  ; Switch cases
  (cond
    ; If the list is null, return an empty list
    ((null? lst) '())
    ; If the first character is the same, we don't want it so skip it
    ((eq? atm (car lst)) (remove_atom atm (cdr lst)))
    ; If the character is diff, call the function again recursively to
    ; finish recursively iterating through each
    (else (if (list? (car lst))
           ; If the first element is a list, recurse through that and the end
           (cons (remove_atom atm (car lst)) (remove_atom atm (cdr lst)))
           ; If it's not a list, move on to the next entry
           (cons (car lst) (remove_atom atm (cdr lst))))
          )))



; Test empty list
(remove_atom 'a '())
; Test single-element list
(remove_atom 'a '(a))
; Test when nothing to replace
(remove_atom 'a '(s c (h e) (m e) i s (t e (r r) i) b l (e)))
; Testing everything 
(remove_atom 'a '(a b (b c (c d)) d (e a) (a b e d k (a d i s (a i d (i d a a o p) l d a e n) a d))))
(remove_atom 'a '(a f (f a c (a b d (e a)) e) g f b))
(remove_atom 'a '(a b c d e f a b a e d a))
(remove_atom 'a '((a b) c () d a c a a))
(remove_atom 'a '(((a (a)) b) c () d a c a a))
(remove_atom 'a '(a b c d a c (a ((a)))a a))
(remove_atom 'z '((h t t p s) (:) (/ /) (w (w) w) (D O T) (y o u t u b e) (D O T) (c (o) m) / (w a t c h) (? v =) (d Q w 4 w 9 W g X c Q)))

