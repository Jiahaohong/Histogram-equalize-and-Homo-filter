function [ acc_gray_histogram ] = acc_gray( gray_histogram )

    [M,N] = size(gray_histogram);
    acc_gray_histogram = zeros(M,N);

    acc_gray_histogram(1) = gray_histogram(1);
    for i = 2:N
        acc_gray_histogram(i) = gray_histogram(i)+acc_gray_histogram(i-1);
    end

end

