echo "compiling character driver"
make
echo "starting to unload scullbuffer driver"
sudo ./scull_unload || true

echo "starting to load scullbuffer driver"
sudo ./scull_load

