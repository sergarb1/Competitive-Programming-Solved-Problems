
#Elimina entradas duplicadas de una lista
def eliminarDuplicadosLista(l):
    res=[]
    for i in l:

        esta = False
        for j in res:
            if i[0]==j[0] and i[1]==j[1]:
                esta=True
                break
        if esta==False:
            res.append(i)
    return res