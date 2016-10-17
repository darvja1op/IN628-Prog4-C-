def quizScorer(correct, incorrect, isChild):
    if(isChild):
        return (correct * 15) - (0.5 * incorrect)
    else:
        return (correct * 10) - (1 * incorrect)

chScore = quizScorer(8, 2, True)
print(chScore)

adScore = quizScorer(8, 2, False)
print(adScore)