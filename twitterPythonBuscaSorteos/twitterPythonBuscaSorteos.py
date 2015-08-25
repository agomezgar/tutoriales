import tweepy
import serial
import time
 
# Consumer keys and access tokens, used for OAuth
consumer_key = ''
consumer_secret = ''
access_token = ''
access_token_secret = '''
 
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
#api.update_status(status=presentacion)
while True:
   
      
      
      try:
           
            tuit=busqueda.next()          
            print ("Texto: ")
            frase= (tuit.text.encode('utf-8'))
            print (frase)
            
            if (not("b'RT" in str(frase))):
                  print ("Tweet original")
                  api.retweet(tuit.id)
                  api.create_friendship(tuit.author.id)
                  time.sleep(10)
                  '''
      except tweepy.TweepError:
            print ("Error de Tweepy")
            time.sleep(60*15)
            busqueda=tweepy.Cursor(api.search, q='#Arduino',lang='es').items()
            continue
            '''
      except StopIteration:
            busqueda=tweepy.Cursor(api.search, q='#Arduino',lang='es').items()
            print ("Busqueda terminada. Descansando...")
            time.sleep(60)
            continue


"""
while True:
      try:
            for follower in tweepy.Cursor(api.followers, id='ieseduardovalen').items(150):
                  api.send_direct_message(user_id=follower.id,text='¡Hola! Te mando DM para agradecerte que sigas al @ieseduardovalen (soy su CM) y para desearte un buen mes de Agosto. ¡Un saludo!')
                  time.sleep(20)
                  tuits=tuits+1
                  if (tuits>20):
                        tuits=0
                        time.sleep(300)
      except tweepy.TweepError:
            print ('We got a timeout ... Sleeping for 15 minutes')
            time.sleep(60*15)
            print ('I am live')
            user = next(users)
            print (user.screen_name)
      except StopIteration:
            break

while(1):
      for tweets in tweepy.Cursor(api.search,q="#Arduino",lang="es").items():
            print (tweets.text)
            if (tweets.retweet_count>50):
                  print ("Retuiteando...")
                  tweets.retweet
                  time.sleep(30)
                  
            tuits+=1
            print(tuits)
            if (tuits>100):
                  tuits=0
                  time.sleep(30)

 
"""
