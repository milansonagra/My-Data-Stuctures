def Max_Profit_FractionalKnapsack(W):

    # CONTRAINTS
    v = [40,66,20,60,30]       # VALUE OF DIFFERENT PILES
    w = [40,30,10,50,20]      # WIGHT OF DIFFERENT PILES
    profit_ratio = []

    current_wight = 0
    current_value = 0

    for i in range(len(v)):
        profit_ratio.append(v[i]/w[i])

    # MAKING GREEDY CHOICE
    while W-current_wight is not 0:
        i = profit_ratio.index(max(profit_ratio))

        if current_wight+w[i] <= W:

            # TO TAKE FULL PILE:
            
            current_value += v[i]
            current_wight += w[i]
        else:

            # TO TAKE FRACTIONAL PILE:
            
            fraction_wight = W-current_wight
            fraction_value = (v[i]*fraction_wight)/w[i]

            current_value += fraction_value
            current_wight += fraction_wight
            print("-->",fraction_wight,", ",fraction_value)
                    
        print(w[i]," ",v[i],"->",current_value,", ",current_wight)
        profit_ratio[i] = 0

    return current_value
