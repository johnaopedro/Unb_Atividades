import subprocess
import os
#Adaptar funções do problema2
def define_e_domain():
    return "(define (problem problemagarra)\n  (:domain gripper-typed)\n"
def objects(salas, bolas):
    salas_str = "  (:objects\n    " + " ".join(salas) + " - room\n"
    bolas_str = "    " + " ".join(bola[0] for bola in bolas) + " - ball)\n"
    return salas_str + bolas_str
def init(salas, bolas):
    init_str = f"  (:init\n    (at-robby {salas[0]})\n    (free left)\n    (free right)\n"
    bolas_str = "    " + " ".join(f"(at {bola[0]} {bola[1]})" for bola in bolas) + "\n  )\n"
    return init_str + bolas_str
def goal(bolas):
    goal_str = "  (:goal (and " + " ".join(f"(at {bola[0]} {bola[2]})" for bola in bolas) + "))\n)\n"
    return goal_str
dominio = """(define (domain gripper-typed)
   (:requirements :typing)
   (:types room ball gripper)
   (:constants left right - gripper)
   (:predicates
    (at-robby ?r - room)            ;; O robô está em uma sala
    (at ?b - ball ?r - room)        ;; Uma bola está em uma sala
    (free ?g - gripper)             ;; A pinça está livre
    (carry ?o - ball ?g - gripper)) ;; Uma pinça está segurando uma bola

   ;; Ação de mover o robô entre salas
   (:action move
       :parameters  (?from ?to - room)
       :precondition (at-robby ?from)
       :effect (and  (at-robby ?to)
             (not (at-robby ?from))))

   ;; Ação de pegar uma bola com uma das pinças, em uma determinada sala
   (:action pick
       :parameters (?obj - ball ?room - room ?gripper - gripper)
       :precondition (and (at ?obj ?room) (at-robby ?room) (free ?gripper))
       :effect (and (carry ?obj ?gripper)
            (not (at ?obj ?room))
            (not (free ?gripper))))

   ;; Ação de soltar uma bola de uma pinça em uma sala específica
   (:action drop
       :parameters (?obj - ball ?room - room ?gripper - gripper)
       :precondition (and (carry ?obj ?gripper) (at-robby ?room))
       :effect (and (at ?obj ?room)
            (free ?gripper)
            (not (carry ?obj ?gripper)))))"""
#----------------------------------------INICIO DA MAIN----------------------------------------#
numsalas, numbolas = input().split()
salas = input().split()
bolas = [input().split() for _ in range(int(numbolas))]
os.chdir("/tmp")
with open("domain.pddl", "w") as fdomain:
    fdomain.write(dominio)
with open("problem.pddl", "w") as fproblem:
    fproblem.write(define_e_domain())
    fproblem.write(objects(salas, bolas))
    fproblem.write(init(salas, bolas))
    fproblem.write(goal(bolas))
try:
    caminho = [
        "python3", "/tmp/dir/software/planners/downward-fdss23/fast-downward.py",
        "--alias", "seq-opt-fdss-2023",
        "--plan-file", "plan",
        "--overall-time-limit", "10",
        "domain.pddl",
        "problem.pddl"
    ]
    subprocess.run(caminho, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, check=True)
    with open("plan", "r") as plan_file:
        print(plan_file.read())
        resposta=plan_file.read()
except Exception:
    print("Erro")