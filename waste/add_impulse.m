function [ output_img ] = add_impulse( input_img, SNR )
%ÎªÍ¼Æ¬Ìí¼Ó½·ÑÎÔëÉù

output_img = input_img;
[M,N] = size(output_img);

noise = M*N*(1-SNR);

for i = 1:noise
    x = randi(N);
    y = randi(M);
    r = randi(2)/2;
    if r == 1
        output_img(y,x) = 255;
    else
        output_img(y,x) = 0;
    end
end
end

