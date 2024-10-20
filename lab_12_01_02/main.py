# Талышева Олеся ИУ7-35Б
# Программа сдвигает циклически элементы массива на k влево и фильтрует его по полным квадратам.

# Импортируем библиотеки
import tkinter as tk
import tkinter.messagebox as mb
from Worker import fork

# Создаём окошко и обозначаем его параметры
window = tk.Tk()
window.geometry(f"620x242+100+200")
window["bg"] = 'aqua'
window.title("Python & C")
window.resizable(0,0)

# Создаётся строчка "Введите массив целых чисел:"
label1 = tk.Label(text="Введите массив целых чисел:", font = ("Calibry", 11))
label1.grid(row = 0, column = 0, sticky = 'w')

# Создаём окошко ввода и обозначаем его параметры, вставляем в него дефолтный массив
arr_str = tk.Entry(justify = tk.LEFT, font = ("Calibry", 15), width = 30)
arr_str.grid(row = 0, column = 1, columnspan = 2, stick = 'we', padx = 5)
arr_str.insert(0, "1 2 3 4 5 6 7 8 9 10")

# Создаётся строчка "На сколько двигать массив влево:"
label2 = tk.Label(text="На сколько двигать массив влево:", font = ("Calibry", 11))
label2.grid(row = 1, column = 0, sticky = 'w')

# Создаём окошко ввода и обозначаем его параметры, вставляем в него дефолтный путь
k_str = tk.Entry(justify = tk.LEFT, font = ("Calibry", 15), width = 30)
k_str.grid(row = 1, column = 1, columnspan = 2, stick = 'we', padx = 5)
k_str.insert(0, "2")

# Создаётся строчка "Циклически сдвинули массив влево:"
label3 = tk.Label(text="Циклически сдвинули массив влево:", font = ("Calibry", 11))
label3.grid(row = 2, column = 0, sticky = 'w')

# Создаём окошко ввода и обозначаем его параметры
stika_go = tk.Entry(justify = tk.LEFT, font = ("Calibry", 15), width = 30)
stika_go.grid(row = 2, column = 1, columnspan = 2, stick = 'we', padx = 5)

# Создаётся строчка "Отфильтровали по полным квадратам:"
label4 = tk.Label(text="Отфильтровали по полным квадратам:", font = ("Calibry", 11))
label4.grid(row = 3, column = 0, sticky = 'w')

# Создаём окошко вывода и обозначаем его параметры
stika_filtr = tk.Entry(justify = tk.LEFT, font = ("Calibry", 15), width = 30)
stika_filtr.grid(row = 3, column = 1, columnspan = 2, stick = 'we', padx = 5)

# Создаём меню
menu = tk.Menu(window) 
window.config(menu = menu)

# Создаёт вкладку меню "Действия" с выпадающим меню с действиями
menu_in = tk.Menu(menu, tearoff = 0)

menu_in.add_command(label = 'Сдвинуть', command = lambda: fork('Сдвинуть', stika_go, stika_filtr, arr_str, k_str))
menu_in.add_command(label = 'Фильтровать', command = lambda: fork('Фильтровать', stika_go, stika_filtr, arr_str, k_str))
menu_in.add_command(label = 'Очистить ввод массива', command = lambda: fork('Очистить ввод массива', stika_go, stika_filtr, arr_str, k_str))
menu_in.add_command(label = 'Очистить ввод k', command = lambda: fork('Очистить ввод k', stika_go, stika_filtr, arr_str, k_str))

menu.add_cascade(label = "Действия", menu = menu_in)


# Создаёт вкладку меню "Информация" с выпадающим меню с информацией об авторе и программе
menu_inf = tk.Menu(menu, tearoff = 0)

menu_inf.add_command(label = 'Информация об авторе', command = lambda: mb.showinfo('Информация об авторе', \
                                                                                   "автор - Талышева ИУ7-35Б"))
menu_inf.add_command(label = 'Информация о программе', command = lambda: mb.showinfo('Информация о программе',\
                                                                                     "Программа сдвигает циклически элементы массива на k влево\n\
и фильтрует его по полным квадратам."))

menu.add_cascade(label = "Информация", menu = menu_inf)


# Функция создаёт кнопку
def make_button(doing):
    return tk.Button(text=doing, bd=7, font=("Calibry", 13), width=25, \
                     command=lambda: fork(doing, stika_go, stika_filtr, arr_str, k_str), \
                     activebackground="salmon", bg="khaki")

# Создаются и отображаются кнопки
make_button('Сдвинуть').grid(row = 4, column = 0, stick = 'wens', padx = 5, pady = 5)
make_button('Фильтровать').grid(row = 4, column = 1, stick = 'wens', padx = 5, pady = 5)
make_button('Очистить ввод массива').grid(row = 5, column = 0, stick = 'wens', padx = 5, pady = 5)
make_button('Очистить ввод k').grid(row = 5, column = 1, stick = 'wens', padx = 5, pady = 5)

# Задаётсяя минимальный размер колонок
for i in range(6):
    window.grid_columnconfigure(i, minsize = 60)

# Задаётсяя минимальный размер строки с кнопками
for i in range(4, 6):
    window.grid_rowconfigure(i, minsize = 60)

# Включается обработчик событий
window.mainloop()
