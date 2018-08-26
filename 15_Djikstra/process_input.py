
if __name__ == "__main__":
    
    f=open('./dijkstraData.txt','r')
    o = open("dijktra.txt",'w')
    for L in f.readlines():
        parts = L.split()
        for edge in parts[1:]:
            i1,i2 = edge.split(",")
            o.write("%d %d %d\n"%(int(parts[0]),int(i1),int(i2)))
    o.close();
    f.close()
