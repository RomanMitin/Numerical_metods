import matplotlib.pyplot as plt
import os.path
from sys import exit 
from sys import argv #Для предачи n_method, u_true, system_

if (len(argv) != 3 and len(argv) != 4):
    print("Incorrect launch")
    exit()

if (not(os.path.exists("./tmp/result.txt"))):  
    print("The file does not exist")
    exit()

with open("./tmp/result.txt") as res:
    all_result = [row.strip() for row in res]


n_method = int(argv[1])

if(argv[2] == '1' or argv[2] == 'True'): #Нужно передавать есть ли точное решение
    u_true = True
else:
    u_true = False

if(len(argv) == 4): #Нужно передавать система или нет, можно опустить тогда считается, что нет
    system_ = argv[3]
else:
    system_ = False

##reference
#info = []
#for i in range(19):
#    info.append(all_result[i].split())
#print(info)

result = []
for i, row in enumerate(all_result):
    if i > 18:
        result.append(row.split())

x = []
v = []
S_ = []

if(u_true):
    u = []
    E = []

if(system_):
    y = []

for i, row in enumerate(result):
    x.append(float(row[2]))
    v.append(float(row[3]))

    if(not(system_)):
        S_.append(abs(float(row[5])))
    else:
        y.append(float(row[4]))
        S_.append(abs(float(row[7])))
    
    if(u_true and not(system_)):
        u.append(float(row[7]))
        E.append(abs(float(row[8])))
    

if n_method == 2:
    name = "Euler method 1 order"
elif n_method == 3:
    name = "Runge Kutta methods 2 order step"
elif n_method == 7:
    name = "Runge Kutta methods 4 order step"
elif n_method == 8:
    name = "Runge Kutta methods 2 order step"
    u_true = False
    system_ = True
else:
    name = "Unknown method"


plt.close()
fig = plt.figure(num = name, figsize=(12, 7))

if(not system_):
    (x_v_u, x_S_E) = fig.subplots(2, 1)
    fig.suptitle(name, fontsize=16, fontweight='bold')

    x_v_u.plot(x, v, c = 'blue', label = 'Численное рещение')
    x_v_u.scatter(x, v, c = 'blue')
    x_v_u.set_xlabel('x')
    if(u_true):
        x_v_u.plot(x, u, c = 'red', label = 'Точное рещение')
        x_v_u.scatter(x, u, c = 'red')

    x_S_E.plot(x, S_, c = 'orange', label = 'ОЛП')
    x_S_E.scatter(x, S_, c = 'orange')
    x_S_E.set_xlabel('x')
    if(u_true):
        x_S_E.plot(x, E, c = 'yellow', label = 'Глобальная погрешность')
        x_S_E.scatter(x, E, c = 'yellow')

    x_v_u.legend(fontsize = 12)
    x_S_E.legend(fontsize = 12)
else:
    ((x_v, x_y), (v_y, x_S)) = fig.subplots(2, 2)
    fig.suptitle(name, fontsize=16, fontweight='bold')

    x_v.plot(x, v, c = 'blue', label = 'Численное рещение v1')
    x_v.scatter(x, v, c = 'blue')
    x_v.set_xlabel('x')
    x_v.set_ylabel('v1')

    x_y.plot(x, y, c = 'blue', label = 'Численное рещение v2')
    x_y.scatter(x, y, c = 'blue')
    x_y.set_xlabel('x')
    x_y.set_ylabel('v2')

    v_y.plot(v, y, c = 'purple', label = 'Фазовый портрет')
    v_y.scatter(v, y, c = 'purple')
    v_y.set_xlabel('v1')
    v_y.set_ylabel('v2')

    x_S.plot(x, S_, c = 'orange', label = 'ОЛП')
    x_S.scatter(x, S_, c = 'orange')
    x_S.set_xlabel('x')
    x_S.set_ylabel('S')

    x_v.legend(fontsize = 12)
    x_y.legend(fontsize = 12)
    v_y.legend(fontsize = 12)
    x_S.legend(fontsize = 12)

plt.show()
