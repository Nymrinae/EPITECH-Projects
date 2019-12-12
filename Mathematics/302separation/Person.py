class Person:
    def __init__(self, index, name, connections):
        self.index = index
        self.name = name
        self.connections = connections

def addFriend(persons, i, p1, p2):
    isRegister = False

    for person in persons:
        if person.name == p1:
            isRegister = True
            person.connections.append(p2)
    if not isRegister:
        p = Person(i, p1, [p2])
        persons.append(p)


def createPersons(content):
    normal = []
    reverse = []
    persons = []

    for i in range(len(content)):
        ppl = content[i].split('-')
        addFriend(persons, i, ppl[0], ppl[1])
        addFriend(persons, i, ppl[1], ppl[0])

    persons = sortPersons(persons)
    return persons

def sortPersons(persons):
    persons = sorted(persons, key=lambda x: x.name)
    
    for n in range(len(persons)):
        persons[n].index = n
    
    return persons
