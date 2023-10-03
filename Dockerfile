# Start from a base image with gcc installed
FROM gcc:latest

# Install the ncursesw library
RUN apt-get update && apt-get install -y libncursesw5-dev

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container
COPY . .

# Build the application
RUN make