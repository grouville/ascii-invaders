#include <stdio.h>
#include <yaml.h>

#define MAX_SPRITES 10
#define MAX_FRAMES 2
#define MAX_LINES 3

typedef struct
{
	char	*frames[MAX_FRAMES][MAX_LINES];
}			Sprite;

Sprite		sprites[MAX_SPRITES];

int	main(void)
{
	FILE *file = fopen("sprites.yaml", "r");
	yaml_parser_t parser;
	yaml_event_t event;

	if (!yaml_parser_initialize(&parser))
	{
		fprintf(stderr, "Failed to initialize the YAML parser\n");
		return (1);
	}

	yaml_parser_set_input_file(&parser, file);

	int done = 0;
	int sprite_index = 0;
	int frame_index = 0;
	int line_index = 0;

	while (!done)
	{
		if (!yaml_parser_parse(&parser, &event))
		{
			fprintf(stderr, "Failed to parse YAML event\n");
			return (1);
		}

		if (event.type == YAML_SCALAR_EVENT)
		{
			if (frame_index < MAX_FRAMES && line_index < MAX_LINES)
			{
				sprites[sprite_index].frames[frame_index][line_index] = strdup((char *)event.data.scalar.value);
				line_index++;
				if (line_index == MAX_LINES)
				{
					line_index = 0;
					frame_index++;
					if (frame_index == MAX_FRAMES)
					{
						frame_index = 0;
						sprite_index++;
					}
				}
			}
		}

		done = (event.type == YAML_STREAM_END_EVENT);
		yaml_event_delete(&event);
	}

	yaml_parser_delete(&parser);
	fclose(file);

	// Print the sprites to verify they were loaded correctly
	for (int i = 0; i < sprite_index; i++)
	{
		for (int j = 0; j < MAX_FRAMES; j++)
		{
			for (int k = 0; k < MAX_LINES; k++)
			{
				printf("%s\n", sprites[i].frames[j][k]);
			}
			printf("\n");
		}
	}

	return (0);
}