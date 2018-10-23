from pydub import AudioSegment
import youtube_dl
import pafy
import tkinter as tk
from tkinter import filedialog,messagebox
from PIL import ImageTk, Image
ventana=tk.Tk()
def descargar(n):
    ventana.filename =  tk.filedialog.askdirectory()+"\\"+n.title+".mp3"
    print (ventana.filename)
    a=n.download()
    m4a_audio = AudioSegment.from_file(a, format="m4a")    
    m4a_audio.export(ventana.filename, format="mp3")
def dispara():
    t=texto.get()
   
    et['text']='Espere un minuto...'
    boton['state']='disabled'
    ventana.filename =  filedialog.askdirectory()
    ydl_opts = {
    'format': 'bestaudio/best',
    'outtmpl': '%(ventana.filename)s.%(title)s.%(ext)s',
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
        

    #ventana.messagebox("¡Audio conseguido!")
texto=tk.Entry(ventana)

texto.pack()
et=tk.Label(ventana,text="Introduzca URL del video a convertir")
et.pack()
boton=tk.Button(ventana,text="Convertir",command=dispara)
boton.pack()
img = ImageTk.PhotoImage(file="logoAprendizTecnologo.png")
panel =tk.Label(ventana, image = img)
panel.image=img
panel.pack(fill = "both", expand = "yes")
ventana.mainloop()
