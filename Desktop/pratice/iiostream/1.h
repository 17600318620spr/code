struct iio_context
{
	struct iio_context_pdata *pdata;
	const struct iio_backend_ops *ops;
	const char *name;
	char *description;

	struct iio_device **devices;
	unsigned int nb_devices;

	char *xml;

	char **attrs;
	char **values;
	unsigned int nb_attrs;
};

struct iio_device 
{
//	const struct iio_context *ctx;
//	struct iio_device_pdata *pdata;
//	void *userdata;

	char *name, *id;

	char **attrs;
	unsigned int nb_attrs;

	char **buffer_attrs;
	unsigned int nb_buffer_attrs;

	char **debug_attrs;
	unsigned int nb_debug_attrs;

//	struct iio_channel **channels;
//	unsigned int nb_channels;

	uint32_t *mask;
	size_t words;
};

struct iio_buffer
{
//	const struct iio_device *dev;
//	struct iio_device *dev;
	void *buffer, *userdata;
//	size_t length, data_length;

//	uint32_t *mask;
//	unsigned int dev_sample_size;
//	unsigned int sample_size;
//	bool is_output, dev_is_high_speed;
};
