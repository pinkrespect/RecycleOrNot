from konlpy.corpus import kobill
from konlpy.tag import Twitter
twit = Twitter()


pos = lambda x: ['/'.join(p) for p in twit.pos(x)]
docs = [kobill.open(i).read() for i in kobill.fileids()]

# get global unique token counts
global_unique = []
global_unique_cnt = []
for doc in docs:
    tokens = pos(doc)
    unique = set(tokens)
    global_unique += list(unique)
    global_unique = list(set(global_unique))
    global_unique_cnt.append(len(global_unique))
    print(len(unique), len(global_unique))

