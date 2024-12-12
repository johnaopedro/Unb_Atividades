; Problem

(define
    (problem turn-it-on)
    (:domain fliaswitch)
    (:objects
        luz
    )
    (:init
        (switch-is-off)
    )
    (:goal
        (switch-is-on)
    )
)
