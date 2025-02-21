import pandas as pd


def process(myline):
    global question
    global myform
    global size
    global across
    
    if myline[0:2] == "F-":
        #print("F line")
        print(myline)

        question = int((myline.split('F-'))[1].split('.')[0])
        mysize.insert(question-1,size)
        #print(f"inserting {size} to question number {question-1}")
        myacross.insert(question-1,across)
        #print(f"inserting {across} to question number {question-1}")
        

        form_name=myline[myline.find('.') + 2:]

        
        # Clean up form name
        # 1. Variograms forms are just normal forms, remove the word "VARIOGRAM" from the form name
        if(form_name[0:9]) == "VARIOGRAM":
            form_name = form_name[10:]
        # 2. Remove † from the end of a form name. They are tags and arent needed
        if(form_name[-1:]) == "†":
            form_name = form_name[:-1]
            print(form_name)
            print("ashu")
        # 3. Double  forms are just normal forms, remove the word "DOUBLE" from the form name
        if(form_name[0:6]) == "DOUBLE":
            form_name = form_name[7:]
        if(form_name[-1:]) == " ":
            form_name = form_name[:-1]

        myform.insert(question,form_name.strip())

        
    elif myline[0:4] == "Down":
        across = size  
        #print(f"across is {across}")
    else:
        #print("normal line")
        if myline[0] == '0' or myline[0] == '1' or myline[0] == '2':
            #print(int(myline[0:2]))
            size = int(myline[0:2])
            #print(f"size is {size}")
        else:
            #print(myline[0:2])
            pass
        pass
    
    
def read_file_line_by_line(file_path):
    try:
        with open(file_path, 'r', encoding='ISO 8859-1') as file:
            for line in file:
                process(line.strip())                
                #input()
            mysize.insert(question,size)
            #print(f"inserting {size} to question number {question}")
            myacross.insert(question,across)
            #print(f"inserting {across} to question number {question}")
    except FileNotFoundError:
        print(f"The file at {file_path} was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


def dotmatrix(form,size,index,across):
    
    print(f"\nForm F-{index} {form}   Size: {size}   Across: {across}")

    if (form == "SQUARE") or (form == 'EIGHT QUEENS SQUARE'):
        for i in range (1, size + 1):
            for j in range (1,size + 1):
                print(".",end = "" )
            print("")

    if form == "DIAMOND":
        mid = ( size + 1 ) / 2
        for i in range (1, size + 1):
            if(i <= mid):
                j_end = ( i * 2 ) - 1
            else:
                j_end = ( size + 1 - i ) * 2 - 1
            
            #print(f"jend = {j_end} {i}")
            
            
            for k in range (1, 1 + int(abs(mid-i))):
                print(" ",end ="")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("")
    
    if form == "PYRAMID":
        mid = int(( size + 1 ) / 2)
        for i in range (1, mid + 1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("")

    if form == "INVERTED PYRAMID":
        mid = int(( size + 1 ) / 2)
        for i in range (mid , 0,-1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("")

    if form == "TRUNCATED PYRAMID":
        mid = int(size / 2)
        for i in range (1, mid + 1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, i * 2 + 1):
                print(".",end = "" )
            print("")

    if form == "INVERTED TRUNCATED PYRAMID":
        mid = int(size / 2)
        for i in range (mid , 0 ,-1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, i * 2 + 1):
                print(".",end = "" )
            print("")            

    if form == "CHEVRON":
        mid = int(( size + 1 ) / 2)
        for i in range (1, mid + 1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("") 
        for i in range ( mid - 1, 0, -1):
            for j in range(1, i + 1):
                print(".",end ="")
            for j in range(1, ( mid - i ) * 2  ):
                print(" ",end ="")
            for j in range(1, i + 1):
                print(".",end ="")
            print("") 


    if form == "RECTANGLE" or form == "CRYPTIC FORM":
        for i in range ( 1, across + 1 , 1):
            for j in range(1, size + 1 ,  1):
                print(".",end ="")
            print("")
        print("")

    if form == "LEFT RHOMBOID":
        for i in range ( 1, across + 1 , 1):
            for j in range(1, i ,  1):
                print(" ",end ="")
            for j in range(1, across + 1 ,  1):
                print(".",end ="")
            print("")
        print("")
    
    if form == "HEXAGON":
        #print(f"size = {size}, across={across}")
        if size < across: # vertex on top orientation
            mid = int(( size + 1 ) / 2)
            for i in range (1, mid + 1):
                j_end = ( i * 2 ) - 1
            
                for k in range (1, 1 + mid - i):
                    print(" ",end ="")
                for j in range (1, j_end + 1):
                    print(".",end = "" )
                print("")  

            for i in range(1, mid - 1, 1):
                for j in range(1, size + 1, 1):
                    print(".",end = "" )  
                print("")    

            for i in range (mid , 0,-1):
                j_end = ( i * 2 ) - 1
            
                for k in range (1, 1 + mid - i):
                    print(" ",end ="")
                for j in range (1, j_end + 1):
                    print(".",end = "" )
                print("") 

        else: # side on top orientation
            mid = int(( across + 1 ) / 2)
            for i in range (1, mid + 1):
                j_end = ( i * 2 ) - 1
            
                for k in range (1, 1 + mid - i):
                    print(" ",end ="")
                for j in range (1, mid + i*2 -1 ):
                    print(".",end = "" )
                print("")  

            for i in range(1, mid ):
                for k in range (0, i):
                    print(" ",end ="")
                for j in range (1, mid + (mid - i) *2 -1 ):
                    print(".",end = "" )
                print("")   

      

    if form == "OCTAGON": # Posibly wrong. Use code from Hollow Octagon
        print(f"size = {size}, across = {across}")
        mid = int(( size + 1 ) / 2)
        for i in range (2, mid + 1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end = "")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("")  
        
        for i in range (1, mid - 2 ):
            for j in range (1, size + 1 ):
                print(".",end = "" )
        print("")

        for i in range (mid , 1, -1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("")                      

    if form == "RIGHT PENTAGON":
        mid = int(( size + 1 ) / 2)
        for i in range (1, mid + 1):
            j_end = ( i * 2 ) - 1
        
            for k in range (1, 1 + mid - i):
                print(" ",end ="")
            for j in range (1, j_end + 1):
                print(".",end = "" )
            print("")
        for i in range ( size - 1, mid, -1):
            #print("ashu")
            for j in range(1, i + 1):
                print(".",end ="")
            print("")

    if form == "PYGMY HOURGLASS":
        dots = int((size + 2 ) / 2)
        flag = 1
        #print(dots)
        for i in range(1,size):
            if (dots > 2) and flag:
                for j in range(1,i):
                    print(" ",end="")
                for j in range(1, dots + 1 ):        
                    print(". ",end ="")
                dots = dots - 1
                print("")
            else:
                for j in range(1,size-i):
                    print(" ",end="")
                for j in range(1, dots + 1 ):        
                    print(". ",end ="")
                dots = dots + 1
                flag = 0
                print("")

    if form == "RIGHT WINDMILL":
        for i in range(1,size+1):
            if ( i < size / 2):
                for j in range(1,int((size-1)/2 + 1) ):
                    print(" ",end="")
                for j in range(1, int((size + 1)/2) + 1 ):        
                    print(".",end ="")
            elif( i == int((size + 1 )/ 2 )):
                for j in range(1, size + 1 ):        
                    print(".",end ="")
            else:
                for j in range(1,int((size + 1)/2 ) + 1 ):       
                    print(".",end ="")    
            print("")
    
    if form == "HOLLOW OCTAGON":
        size = int(( size + 2 ) / 3)
        print(f"size is {size}")
        for i in range(1,size):
            for j in range(1,size - i + 1):
                print(" ",end="")
            for j in range(1, (i * 2) -2 + size + 1):
                print(".",end="")
            print("")    
        for i in range(1,size+1):
            for j in range(1, ( size * 3 ) - 2 + 1):
                print(".",end="")
            print("")
        for i in range(size,1,-1):
            for j in range(1,size - i + 1):
                print(" ",end="")
            for j in range(1, (i * 2) -2 + size + 1):
                print(".",end="")
            print("")
        print("")

    if form == "LEFT WINDMILL":
            for i in range(1,size+1):
                if ( i < size / 2):
                    for j in range(1, int((size + 1)/2) + 1 ):        
                        print(".",end ="")
                elif( i == int((size + 1 )/ 2 )):
                    for j in range(1, size + 1 ):        
                        print(".",end ="")
                else:
                    for j in range(1,int((size-1)/2 + 1) ):
                        print(" ",end="")
                    for j in range(1,int((size + 1)/2 ) + 1 ):       
                        print(".",end ="")    
                print("")

# Code starts here 

myfile="C:\TURBOC3\Projects\python\Forms\Form Input.txt"
question = 1
across = 0
myform=[""]
mysize=[]
myacross=[]
good_forms=['INVERTED TRUNCATED PYRAMID', 'DIAMOND',  'SQUARE', 'EIGHT QUEENS SQUARE', 'PYRAMID','TRUNCATED PYRAMID', 'INVERTED PYRAMID','LEFT RHOMBOID',
            'CHEVRON','RECTANGLE','PYGMY HOURGLASS','RIGHT WINDMILL','LEFT WINDMILL','OCTAGON','RIGHT PENTAGON','HEXAGON','HOLLOW OCTAGON','CRYPTIC FORM']
size = 0

read_file_line_by_line(myfile)
print(myform)
print(mysize)
print(myacross)


for i in range(1,len(myform)):
    if myform[i] in good_forms:
        dotmatrix(myform[i],mysize[i],i,myacross[i])
    else:
        print(f"Form F-{i} x{myform[i]}x is not standard")

#dotmatrix("HOLLOW OCTAGON",19,1,19)
#hexagon needs to be fixed