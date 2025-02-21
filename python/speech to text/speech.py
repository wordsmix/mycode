import speech_recognition as sr
points = {}

def voice_to_text():
    # Initialize recognizer
    flag = 0
    counter = 0
    global points
    papa_points = 0
    small_points = 0
    mummy_points = 0

    
    while (flag == 0):
        try:
            print(f"flag is {flag}")
            recognizer = sr.Recognizer()
            # Use the microphone as the source of audio
            with sr.Microphone() as source:
                print("Please speak something...")
                # Adjust the recognizer sensitivity to ambient noise
                recognizer.adjust_for_ambient_noise(source)
                # Capture the audio from the microphone
                
                audio = recognizer.listen(source,timeout=5)
                try:
                    # Listen for some time or until timeout
                    audio = recognizer.listen(source, timeout=5)
                except sr.WaitTimeoutError:
                    print("Listening timed out while waiting for phrase to start")
                    return None
            
                # Recognize speech using Google Web Speech API
                text = recognizer.recognize_google(audio)
                if text == "end":
                    flag = 1
                    print(f"inner flgis {flag}")
                                                
                print("You said: " + text)
                key = text.lower().split()
                
                print(f"first word is {key[0]}")
                if key[0] == "points":
                    if key[1] == "papa":
                        papa_points = key[2]
                    if key[1] == "mummy":
                        mummy_points = key[2]
                    if key[1] == "small":
                        small_points = key[2]
                    print(f"papa : {papa_points}, mummy : {mummy_points}, smalley:{small_points}")
                if key[0] == "over":
                    points[counter] = (papa_points,mummy_points,small_points)
                    counter = counter + 1
                    

        except sr.UnknownValueError:
            print("Sorry, I could not understand the audio")
        except sr.RequestError:
            print("Sorry, there was an error with the Google Web Speech API")
       

if __name__ == "__main__":
    voice_to_text()
    print(points)