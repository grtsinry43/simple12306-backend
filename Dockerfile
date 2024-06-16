FROM drogonframework/drogon:latest
LABEL authors="grtsinry43"

# Set the working directory
WORKDIR /app

# Clone and build jwt-cpp
RUN git clone https://github.com/Thalhammer/jwt-cpp.git && \
    cd jwt-cpp && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make install

# Copy your project into the container
COPY . /app
COPY config.json /

# Build your project
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

# Expose the port your app runs on \
EXPOSE 5555

# Run your app
CMD ["./build/simple12306-backend"]