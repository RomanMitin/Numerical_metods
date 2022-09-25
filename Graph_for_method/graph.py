import matplotlib.pyplot as plt
import os.path
from sys import argv #Для предачи u_true, n_method
#Не забудь проверить после компиляции
#+ отдельно программу для основной задачи №2 с 4 графиками u_x, u'_x, u_u", S_x

if len(argv) != 3:
    print("Incorrect launch")
    exit()

if (not(os.path.exists("../tmp/result.txt"))):  
    print("The file does not exist")
    exit()

with open("../tmp/result.txt") as res:
    all_result = [row.strip() for row in res]

info = all_result[0].split()
n_method = int(argv[1]) #Нужно добавить в вывод имя или номер метода
if(argv[2] == '1' or argv[2] == 'True'): #Нужно передавать есть ли точное решение
    u_true = True
else:
    u_true = False

result = []

for i, row in enumerate(all_result):
    if i > 0:
        result.append(row.split())

x = []
v = []
S_ = []

if(u_true):
    u = []
    E = []

for i, row in enumerate(result):
    x.append(float(row[2]))
    v.append(float(row[3]))
    S_.append(abs(float(row[5])))
    if(u_true):
        u.append(float(row[7]))
        E.append(abs(u[i]-v[i]))

if n_method == 3:
    name = "Runge_Kutta_methods_3_order_step"
else:
    name = "Unknown method"

fig = plt.figure(num = name, figsize=(12, 7))
(x_v_u, x_S_E) = fig.subplots(2, 1)
fig.suptitle(name, fontsize=16, fontweight='bold')

x_v_u.plot(x, v, c = 'blue', label = 'Численное рещение')
x_v_u.scatter(x, v, c = 'blue')
if(u_true):
    x_v_u.plot(x, u, c = 'red', label = 'Точное рещение')
    x_v_u.scatter(x, u, c = 'red')

x_S_E.plot(x, S_, c = 'orange', label = 'ОЛП')
x_S_E.scatter(x, S_, c = 'orange')
if(u_true):
    x_S_E.plot(x, E, c = 'yellow', label = 'Глобальная погрешность')
    x_S_E.scatter(x, E, c = 'yellow')

x_v_u.legend(fontsize = 12)
x_S_E.legend(fontsize = 12)
plt.show()