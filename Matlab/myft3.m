function [ outputMat ] = myft3( inputMat )
%
%
[M0,N0] = size(inputMat);
M1 = find_upper_2n(M0);
N1 = find_upper_2n(N0);
outputMat = double(zeros(M1,N1));
tempMat = double(zeros(M1,N1));
inputMat(M1,N1) = 0;
inputMat = double(inputMat);

for x = 1:N1
    tempMat(:,x) = myfft( inputMat(:,x).' ).';
end
for y = 1:M1
    outputMat(y,:) = myfft( tempMat(y,:) );
end

end

function [ outputMat ] = myfft( inputMat )

[M,N] = size(inputMat);
if mod(N,2)==0
    oddMat = myfft( inputMat(1:2:end) );
    evenMat = myfft( inputMat(2:2:end) );
    for u=1:N/2
        evenMat(u) = evenMat(u)*exp(-1j*2*pi*(u-1)/N);
    end
    foreMat = (oddMat + evenMat);
    backMat = (oddMat - evenMat);
    outputMat = cat(2,foreMat,backMat);
else
    outputMat = inputMat;
end
    
end
   
function [ output ] = find_upper_2n( input )
output = 1;
while output < input
    output = output*2;
end

end