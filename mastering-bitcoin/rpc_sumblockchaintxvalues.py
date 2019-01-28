from bitcoin.rpc import RawProxy

p = RawProxy()

lastblockheight = p.getblockcount()

total_value = 0

# Skip the block of height 0 since the genesis block coinbase is not considered
# an ordinary transaction and cannot be retrieved
for blockheight in range(1, lastblockheight + 1):
    blockhash = p.getblockhash(blockheight)
    block = p.getblock(blockhash)
    transactions = block['tx']
    block_value = 0

    for txid in transactions:
        tx_value = 0
        raw_tx = p.getrawtransaction(txid)
        decoded_tx = p.decoderawtransaction(raw_tx)

        for output in decoded_tx['vout']:
            tx_value += output['value']

        block_value += tx_value

    total_value += block_value
    print(f"blockheight = {blockheight}, total_value = {total_value}")

print("Total value of BTC moved in blockchain: ", total_value)

