def value_counts_to_list(data, key_name):
    return [
        { key_name: key, 'value': value}
        for key, value in data.value_counts().items()
    ]