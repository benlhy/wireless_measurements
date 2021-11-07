import asyncio
from bleak import BleakScanner,BleakClient
from bleak.exc import BleakError

CHARACTERISTIC_UUID = "0000ffe1-0000-1000-8000-00805f9b34fb"
DEVICE_MAC = "A8:A9:8B:B2:B0:78"


async def run():


    def notification_handler(sender, data):
        """Simple notification handler which prints the data received."""
        print("{0}: {1}".format(sender, data))


    def handle_disconnect(_: BleakClient):
            print("Device was disconnected, goodbye.")
            # cancelling all tasks effectively ends the program
            for task in asyncio.all_tasks():
                task.cancel()
    
    device = await BleakScanner.find_device_by_address(DEVICE_MAC,timeout=10)
    if not device:
        raise BleakError("Device not found!")
    async with BleakClient(device, disconnected_callback=handle_disconnect) as client:
        print("Client is connected!")
        await client.start_notify(CHARACTERISTIC_UUID, notification_handler)
        #loop = asyncio.get_event_loop()
        while 1:
            await asyncio.sleep(1) # never exit

loop = asyncio.get_event_loop()
loop.create_task(run())
try:
    loop.run_forever()
except asyncio.CancelledError:
    # task is cancelled on disconnect, so we ignore this error
    pass
finally:
    loop.close()
