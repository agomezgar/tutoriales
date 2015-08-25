
import tweepy
import serial
import time
 
# Consumer keys and access tokens, used for OAuth
consumer_key = ''
consumer_secret = ''
access_token = ''
access_token_secret = ''
 
# OAuth process, using the keys and tokens
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
 
# Creation of the actual interface, using authentication
api = tweepy.API(auth)
# Sample method, used to update a status
#api.update_status(status='En fin... La noche es joven...')
print ("Preparando búsqueda:")


busqueda=tweepy.Cursor(api.search, q='sorteo RT',lang='es').items()
#El string presentacion me permite avisar a mis followers que inicio al bot.
presentacion='Atentos followers que inicio experimento con bot buscasorteos. Don\'t be afraid. Ni puto caso, vamos. Con fecha: '+time.strftime("%I:%M:%S")
print (presentacion)
api.update_status(status=presentacion)
while True:
   
      
      
      try:
           
            tuit=busqueda.next()          
            print ("Texto: ")
            frase= (tuit.text.encode('utf-8'))
            print (frase)
            
            if (not("b'RT" in str(frase))):
                  print ("Tweet original")
                  tuit.retweet()
                  api.create_friendship(tuit.author.id)
                  time.sleep(10)
                 
      except TweepError:
            print ("Error de Tweepy")
            time.sleep(10)
            busqueda=tweepy.Cursor(api.search, q='#Arduino',lang='es').items()
            continue
            
     
      except StopIteration:
            busqueda=tweepy.Cursor(api.search, q='#Arduino',lang='es').items()
            print ("Busqueda terminada. Descansando...")
            time.sleep(60)
            continue

