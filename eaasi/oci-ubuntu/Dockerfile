FROM ubuntu:noble@sha256:72297848456d5d37d1262630108ab308d3e9ec7ed1c3286a32fe09856619a782

RUN apt-get update && apt-get install --no-install-recommends -y \
    python3-pip \
    python3-venv && \
    rm -rf /var/lib/apt/lists/* && \
    python3 -m venv /opt/venv

RUN /opt/venv/bin/pip install --no-cache-dir numpy

CMD ["/opt/venv/bin/python"]
