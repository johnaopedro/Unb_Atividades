def define_e_domain(): #INICIO do PDDL(define e domain)
    print("(define (problem problemagarra)")
    print("  (:domain gripper-typed)")
def objects(salas, bolas): #Gerar objects(inicio e definição das variáveis)
    print("  (:objects")
    salas_str = ""
    for sala in salas:
        salas_str += sala + " "
    bolas_str = ""
    for bola in bolas:
        bolas_str += bola[0] + " "
    print(salas_str + "- room")
    print(bolas_str + "- ball)")
def init(salas, bolas): #Gerar init(inicio e estado inicial)
    print(" (:init (at-robby " + salas[0] + ")")
    print("    (free left)")
    print("    (free right)")
    bolas_str = ""
    for i, bola in enumerate(bolas):
        if i > 0:
            bolas_str += " "
        bolas_str += "(at " + bola[0] + " " + bola[1] + ")"
    print(bolas_str+"  )")
def goal(bolas): #Gerar o goal(inicio e estado final)
    estado_final = ""
    for i, bola in enumerate(bolas):
        if i > 0:
            estado_final += " "
        estado_final += "(at " + bola[0] + " " + bola[2] + ")"
    print(" (:goal (and " + estado_final + "  )))")
#----------------------------------------INICIO DO CODIGO----------------------------------------#
#Numero de salas e bolas
numsalas, numbolas = input().split()
nsalas = int(numsalas)
nbolas = int(numbolas)
#Salas(usarei join para string, no entanto focar em sala atual e destino)
salas = input().split()
#Informacoes(objeto,salaAtual,salaDestino)
init_e_goal = []
for i in range(nbolas):
    inf = input().split()
    init_e_goal.append((inf[0], inf[1], inf[2]))
#Chamada do inicio do PDDL (define e domain)
define_e_domain()
#Chamada do objects(inicio e definição das variáveis)
objects(salas, init_e_goal)
#Chamada do init(inicio e estado inicial)
init(salas, init_e_goal)
#Chamada do goal(inicio e estado final)
goal(init_e_goal)