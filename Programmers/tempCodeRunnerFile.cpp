int decimal = 1;
    for(int i = vec.size() - 1; i >= 0; i++, decimal*=3) {
        answer += vec[i] * decimal;
    }