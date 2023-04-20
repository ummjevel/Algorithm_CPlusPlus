def solution(keymap, targets):
    answer = []
    for target in targets:
        cnt = 0
        for t in target:
            keymaps = [101]*len(keymap)
            for i in range(len(keymap)):
                if t in keymap[i]:
                    keymaps[i] = keymap[i].index(t)
            if min(keymaps) == 101:
                cnt = -1
                break
            else:
                cnt += min(keymaps) + 1

        answer.append(cnt)
    return answer