function [ gray_histogram ] = count_gray( input_img )

    %�����ͻҶȼ��ǳ������飬�����±���ǻҶȼ�����������Ϊ�ûҶȼ������ظ���
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

