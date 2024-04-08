function [Achap,bchap,flag]=EliminationGauss(A,b)
n=size(A,1);
Achap=A;
bchap=b;
flag=1;
    for k=1:n
        if abs(A(k,k))<%eps
            //print("Arreter l'algorithme et donner un message d'erreur");
            flag=0;
            break;
        else
            for i=k+1:n
                c=Achap(i,k)/Achap(k,k);
                Achap(i,k)=0;
                bchap(i)=bchap(i)-c*bchap(k);
                for j=k+1:n
                    Achap(i,j)=Achap(i,j)-c*Achap(k,j);
                end
            end
         end
    end
endfunction

