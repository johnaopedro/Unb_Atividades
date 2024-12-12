(define 
    (problem gripper-MojB)
    (:domain gripper-typed)
    (:objects ;;Os objetos que iremos trabalhar
        rooma - room
        roomb - room
        ball1 - ball
        ball2 - ball
        ball3 - ball
        ball4 - ball
    )
    (:init ;;Esta sao as condicoes iniciais
        (at-robby rooma)
        (free left)
        (free right)
        (at ball1 rooma)
        (at ball2 rooma)
        (at ball3 rooma)
        (at ball4 rooma))
    (:goal (and ;;Este e o objetivo
        (at ball4 roomb)
        (at ball3 roomb)
        (at ball2 roomb)
        (at ball1 roomb))
    )
)
;;PREDICADOS USADOS:
;;(at-robby ?r - room) O robô está em uma sala
;;(free ?g - gripper) A pinça está livre
;;(at ?b - ball ?r - room) Uma bola está em uma sala