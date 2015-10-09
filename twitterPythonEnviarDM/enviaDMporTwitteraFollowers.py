import tweepy
import time
 
# Consumer keys y access tokens, usados para el OAuth por parte de nuestra app
# Tienes que conseguirlas en https://dev.twitter.com/apps
consumer_key = 'XXXXXXXXXXXXXXXXXXXX'
consumer_secret = 'XXXXXXXXXXXXXXXXXXXXXXXXXXX'
access_token = 'XXXXXXXXXXXXXXXXXXXXXXXXXXX'
access_token_secret = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
dm='¡Hi!Estoy preparando un videotutorial sobre bots en Twitter y aprovecho para mandarte este DM y un saludo. Espero que no te importe.'

# Ponemos nuestra api en marcha
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

#Empezamos nuestra paginacion de followers
print ("Preparando followers:")
followers=tweepy.Cursor(api.followers).items(200)
print ("¡Followers preparados!")
#Bloques try y except para capturar error y el final de la iteracion
while True:
      try:
            print("Ahora viene el follower: ")
            follower=followers.next()
            print(follower.screen_name)
            print ("Enviando mensaje directo: ")
            api.send_direct_message(user_id=follower.id,text=dm)
            print ("¡DM enviado!")
            time.sleep(10)
      except tweepy.TweepError:
            print("Error de Tweepy")
            time.sleep(15*60)
            continue
      except StopIteration:
            print ("¡Terminé!")
            break


