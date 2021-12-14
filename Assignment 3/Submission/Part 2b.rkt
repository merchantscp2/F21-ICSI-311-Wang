; Part 2b: Replacing Atoms -- Merchant, A

; Things to consider:
; Nested lists must be considered
; Think of an atom as a character

; Function to replace any atom in a list even deeply nested
 (define (replace_atom atm rep lst)
  ; Switch cases
  (cond
    ; If the list is null, return an empty list
    ((null? lst) '())
    ; If the first character is the same, we don't want it so skip it
    ((eq? atm (car lst)) (cons rep (replace_atom atm rep (cdr lst))))
    ; If the character is diff, call the function again recursively to
    ; finish recursively iterating through each
    (else (if (list? (car lst))
           ; If the first element is a list, recurse through that and the end
           (cons (replace_atom atm rep (car lst)) (replace_atom atm rep (cdr lst)))
           ; If it's not a list, move on to the next entry
           (cons (car lst) (replace_atom atm rep (cdr lst))))
          )))

; Test empty list
(replace_atom 'a 'z '())
; Test single-element list
(replace_atom 'a 'z '(a))
; Test when nothing to replace
(replace_atom 'a 'z '(s c (h e) (m e) i s (t e (r r) i) b l (e)))
; Testing function nested
(replace_atom ': '\; (replace_atom 'o '0 '((h t t p s) (:) (/ /) (w (w) w) (D O T) (y o u t u b e) (D O T) (c (o) m) / (w a t c h) (? v =) (d Q w 4 w 9 W g X c Q))))
; Testing everything 
(replace_atom 'a 'z '(a b (b c (c d)) d (e a) (a b e d k (a d i s (a i d (i d a a o p) l d a e n) a d))))
(replace_atom 'a 'z '(a f (f a c (a b d (e a)) e) g f b))
(replace_atom 'a 'z '(a b c d e f a b a e d a))
(replace_atom 'a 'z '((a b) c () d a c a a))
(replace_atom 'a 'z '(((a (a)) b) c () d a c a a))
(replace_atom 'a 'z '(a b c d a c (a ((a)))a a))

