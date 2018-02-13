import Tkinter as tk

root = tk.Tk()

logo = tk.PhotoImage(file="snake_image.gif")
logolabel = tk.Label(root,image=logo).pack(side="right")

explaination = """At present, only GIF and PPM/PGM
formats are supported, but an interface 
exists to allow additional image file
formats to be added easily."""

explanationlabel = tk.Label(root,
                            justify=tk.LEFT,
                            padx = 10,
                            text = explaination).pack(side="left")

root.mainloop()