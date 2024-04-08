function [Achap,bchap,flag]=EliminationGauss(A,b)
n=size(A,1);
Achap=A;
bchap=b;
flag=1;
L=I(n,n);
    for k=1:n
        if abs(A(k,k))<%eps
            print("Arreter l'algorithme et donner un message d'erreur");
            flag=0;
            break;
        else
            for i=k+1:n
                L(i,k)=Achap(i,k)/A(k,k);
                Achap(i,k)=0;
                for j=k+1:n
                    Achap(i,j)=Achap(i,j)-L(i,k)*Achap(k,j);
                end
            end
         end
    end
endfunction
