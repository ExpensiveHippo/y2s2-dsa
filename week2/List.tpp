template <typename ItemType>
List<ItemType>::List() : size(0) {}

template <typename ItemType>
bool List<ItemType>::isEmpty()
{
    return size == 0;
}

template <typename ItemType>
int List<ItemType>::getLength()
{
    return size;
}

template <typename ItemType>
bool List<ItemType>::add(const ItemType *item)
{
    if (size >= MAX_SIZE)
    {
        return false;
    }
    items[size] = const_cast<ItemType *>(item);
    size++;
    return true;
}

template <typename ItemType>
bool List<ItemType>::add(const int index, const ItemType *item)
{
    if (index < 0 || index > size || size >= MAX_SIZE)
    {
        return false;
    }
    int i = ++size;
    while (i > index)
    {
        items[i] = items[i - 1];
        i--;
    }
    items[index] = const_cast<ItemType *>(item);
    return true;
}

template <typename ItemType>
bool List<ItemType>::remove(const int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }
    int i = index;
    while (i < size)
    {
        items[i] = items[i + 1];
        i++;
    }
    size--;
    return true;
}

template <typename ItemType>
ItemType *List<ItemType>::at(const int index)
{
    if (index < 0 || index > size)
    {
        return nullptr;
    }
    return items[index];
}

template <typename ItemType>
ItemType *List<ItemType>::find(const ItemType &toFind)
{
    for (int i = 0; i < size; i++)
    {
        if (*items[i] == toFind)
        {
            return items[i];
        }
    }
    return nullptr;
}

template <typename ItemType>
void List<ItemType>::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] " << *items[i] << std::endl;
    }
}