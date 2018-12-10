from pydub import AudioSegment
import youtube_dl
import pafy
import tkinter as tk
from tkinter import filedialog,messagebox
from PIL import ImageTk, Image
import sys
ventana=tk.Tk()

def dameAudio():
    t=texto.get()
    et['text']='Espere un minuto...'
    boton['state']='disabled'
    boton2['state']='disabled'

    archivo = str( filedialog.askdirectory())+"/"
    ydl_opts = {
    'format': 'bestaudio/best',
    'outtmpl': archivo+'%(title)s.%(ext)s',
    'postprocessors': [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec': 'mp3',
        'preferredquality': '192',
        }],
    }
    with youtube_dl.YoutubeDL(ydl_opts) as ydl:
        
        ydl.download([t])
        tk.messagebox.showinfo("¡Conseguido!","¡El video se ha bajado correctamente!")
        et['text']="Introduzca URL del video a convertir"
        texto.delete(0,tk.END)
        boton['state']='normal'
        boton2['state']='normal'       

def dameVideo():
    t=texto.get()
    et['text']='Espere un minuto...'
    boton['state']='disabled'
    boton2['state']='disabled'
    
    archivo = str( filedialog.askdirectory())+"/"
    ydl_opts = {
        'format':'136+140/best',
        'outtmpl': archivo+'%(title)s.%(ext)s',
    }
    with youtube_dl.YoutubeDL(ydl_opts) as ydl:
        
        ydl.download([t])
        tk.messagebox.showinfo("¡Conseguido!","¡El video se ha bajado correctamente!")
        et['text']="Introduzca URL del video a convertir"
        texto.delete(0,tk.END)
        boton['state']='normal'       
        boton2['state']='normal'       

    #ventana.messagebox("¡Audio conseguido!")
texto=tk.Entry(ventana)
texto.pack()
et=tk.Label(ventana,text="Introduzca URL del video a convertir")
et.pack()
boton=tk.Button(ventana,text="MP3",command=dameAudio)
boton.pack(side=tk.LEFT,padx=10)
boton2=tk.Button(ventana,text="MP4",command=dameVideo)
boton2.pack(side=tk.RIGHT,padx=10)
img = ImageTk.PhotoImage(file="logoAprendizTecnologo.png")
panel =tk.Label(ventana, image = img)
panel.image=img
panel.pack(fill = "both", expand = "yes")
ventana.mainloop()
