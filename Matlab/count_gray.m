function [ gray_histogram ] = count_gray( input_img )

    %建立和灰度级登场的数组，数组下标就是灰度级，数组内容为该灰度级的像素个数
    [M,N] = size(input_img);
    gray_histogram = zeros(1,256);

    for i = 1:M
        for j = 1:N
            gray_level = input_img(i,j);
            gray_histogram(gray_level+1) = gray_histogram(gray_level+1) +1;
        end
    end

    gray_histogram = gray_histogram / M / N;

end

